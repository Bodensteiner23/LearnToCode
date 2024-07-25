/* ============================= Variables ============================ */
const standardRowsForFrankys = 11
const col_1_Description = ["1er *", "2er **", "3er ***", "4er ****", "5er *****", "6er ******",
    "Gesamt", "Bonus", "Gesamt oben", "Dreierpasch", "Viererpasch", "Full House", "Little Strada",
    "Big Strada", "Knonffel", "Letzter Ausweg", "Gesamt unten", "Gesamt oben", "Endsumme"]

const col_2_Description = ["nur Einser", "nur Zweier", "nur Dreier", "nur Vierer", "nur Fünfer", "nur Sechser",
    "---->", "plus 35", "---->", "alles zählt", "alles zählt", "25 Punkte", "30 Punkte", "40 Punkte", 
    "50 Punkte", "alles zählt", "---->", "---->", "---->"]

    
let tableCols = null
let playerNames = null
let tableData = []
/* ============================= Functions ============================ */
function checkForTableData() {
    if (localStorage !== null) {
        let retrievedTableCols = sessionStorage.getItem("tableCols")
        // @ts-ignore
        tableCols = JSON.parse(retrievedTableCols)
    
        let retrievedNameData = sessionStorage.getItem("playerNames")
        // @ts-ignore
        playerNames = JSON.parse(retrievedNameData)

        let retrievedTableData = sessionStorage.getItem("tableData")
        // @ts-ignore
        tableData = JSON.parse(retrievedTableData)
    }
}

checkForTableData()

document.addEventListener('DOMContentLoaded', (event) => {
    let tbl = document.getElementById("table");

    if (tbl) {
        // Add event listeners to each cell
        for (let i = 1; i < tbl.rows.length - 1; i++) {
            for (let j = 1; j < tbl.rows[i].cells.length; j++) {
                tbl.rows[i].cells[j].addEventListener('input', function() {
                    updateSumRow();
                });
            }
        }
    }
});

function updateSumRow() {
    let tbl = document.getElementById("table");

    if (tbl) {
        let totalRows = tbl.rows.length - 1;
        let totalCols = tbl.rows[0].cells.length;
        let sumRow = tbl.rows.length - 1;

        for (let i = 1; i < totalCols; i++) {
            let sum = 0;
            for (let j = 1; j < totalRows; j++) {
                let cellValue = tbl.rows[j].cells[i].innerHTML;
                if (cellValue != "-") {
                    sum += Number(cellValue);
                }
            }
            tbl.rows[sumRow].cells[i].innerHTML = sum;
        }
    }
}

createTable(standardRowsForFrankys, tableCols, tableData, playerNames)




function createTable(row, col, tableData, playerNames) {

    const tbl = document.querySelector("#table")
    const tblBody = document.createElement("tbody")

    // Creating cells
    for (let i = 0; i < row; i++) {
        const row = document.createElement("tr")

        for (let j = 0; j < col; j++) {
            const cell = document.createElement("td")
            if (i == 0 && j == 0) {
                // Create "Runden" cell
                const cellText = document.createTextNode("Knoffel")
                cell.append(cellText)
            } else if (i == 0 && j != 0) {
                // Create cells with player names in first row
                const cellText = document.createTextNode(playerNames[j])
                cell.append(cellText)
            } else if (i != 0 && j == 0) {
                // Create round counter cells
                const cellText = document.createTextNode(String(i))
                cell.append(cellText)
            } else {
                // Create rest of the cells
                cell.contentEditable = "true"
            }
            row.append(cell)
        }
        tblBody.append(row)
    }
    if (tbl) {
        tbl.append(tblBody)
    }

    addSumRowToTable(col)

    addEventListenerToTableDataCells()

    addDataToTable()
    
}

function addNewRow() {
    let tbl = document.getElementById("table");
    if (tbl) {
        let newRow = tbl.insertRow(tbl.rows.length - 1); // Insert before the sum row
        let nextRoundNumber = tbl.rows.length - 2; // Calculate the next round number

        for (let i = 0; i < tbl.rows[0].cells.length; i++) {
            let newCell = newRow.insertCell(i);
            if (i == 0) {
                // Set the first cell to the next round number
                newCell.innerHTML = String(nextRoundNumber);
            } else {
                newCell.contentEditable = true; // Make the cell editable
                newCell.addEventListener('input', function() {
                    updateSumRow();
                });
            }
        }
    }
}


function addSumRowToTable(tableCols) {
    let tbl = document.getElementById("table")
    // @ts-ignore
    let row = tbl.insertRow()
    for (let i = 0; i < tableCols; i++) {
    
        let cell = row.insertCell(i)
    
        if (i == 0) {
            let cellText = document.createTextNode("Summe")
            cell.appendChild(cellText)
        }
    }
}


function addEventListenerToTableDataCells() {
    
    const inputCells = document.querySelectorAll("td")
    for (let i = 0; i < inputCells.length; i++) {
        inputCells[i].addEventListener("keypress", evt => {
            if((evt.key >= "0" && evt.key <= "9") || evt.key === "-") {
                setTimeout(updateSumRow, 0)
                setTimeout(addDataToStorage, 0)
            } else {
                evt.preventDefault()
            }
        })
    }
}


function updateSumRow() {
    let tbl = document.getElementById("table")

    if (tbl) {
        // Get the maximum amount of cells
        // @ts-ignore
        let totalRows = tbl.rows.length - 1         
        // @ts-ignore
        let totalCols = tbl.rows[0].cells.length
        // @ts-ignore
        let sumRow = tbl.rows.length - 1

        for (let i = 1; i < totalCols; i++) {
            let sum = null
            for (let j = 1; j < totalRows; j++) {
                // @ts-ignore
                let cellValue = tbl.rows[j].cells[i].innerHTML
                if (cellValue != "-") {
                    // Don't update cell if -
                    // @ts-ignore
                    sum += Number(cellValue)
                } 
            }
            // @ts-ignore
            tbl.rows[sumRow].cells[i].innerHTML = sum

        }
    }
}


function addDataToStorage() {
    let tbl = document.getElementById("table")

    if (tbl) {
        // Get the maximum amount of cells
        // @ts-ignore
        let totalRows = tbl.rows.length - 1         
        // @ts-ignore
        let totalCols = tbl.rows[0].cells.length
        let tableDataArray = []

        for (let i = 1; i < totalCols; i++) {
            for (let j = 1; j < totalRows; j++) {
                // @ts-ignore
                let cellValue = tbl.rows[j].cells[i].innerHTML
                tableDataArray.push(cellValue)
            }
        }
        sessionStorage.setItem("cellData", JSON.stringify(tableDataArray))
    }
}


function addDataToTable() {
    let tbl = document.getElementById("table")

    if (tbl) {
        // Get the maximum amount of cells
        // @ts-ignore
        let totalRows = tbl.rows.length - 1         
        // @ts-ignore
        let totalCols = tbl.rows[0].cells.length

        let k = 0

        for (let i = 1; i < totalCols; i++) {
            for (let j = 1; j < totalRows; j++) {
                if (tableData[k]) {
                    // @ts-ignore
                    tbl.rows[j].cells[i].innerHTML = tableData[k]
                }
                // Increment k to add value for next cell
                k++
            }
        }
    }
}