/* ============================= Variables ============================ */
const standardRowsForFrankys = 21
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
                const cellText = document.createTextNode("Runde")
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
    
    // ToDo: Add Event Button in the Div and remove dynamic generation
    // displayEventCardsButton()
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