/* ============================= Variables ============================ */
const playerCountButton = document.getElementById("player_count")
const heading = document.getElementById("player_count_heading")
const standardRowsForFrankys = 21
let tableCols = 0  

/* ============================= Functions ============================ */


function initEventListeners() {

    if (playerCountButton) {
        playerCountButton.addEventListener("click", playerCountButtonClicked)
    }
}

initEventListeners()


function playerCountButtonClicked() {
    // Disappear Button and Heading
    if (playerCountButton) {
        playerCountButton.style.display = "none"
    }
    if (heading) {
        heading.style.display = "none"
    }


    let userPlayerCount = prompt("Spieleranzahl eingeben: ")
    let playerNames = [""]
    for (let i = 0; i < Number(userPlayerCount); i++) {
        let userPlayerNames = prompt("Namen der Spieler eingeben: ")
        // @ts-ignore
        playerNames.push(userPlayerNames)
    }

    tableCols = playerNames.length

    createTable(standardRowsForFrankys, tableCols, playerNames)
}

// Test Commit2
function createTable(row, col, playerNames) {
    const tbl = document.createElement("table")
    tbl.id = "table"
    const tblBody = document.createElement("tbody")

    // Creating cells
    for (let i = 0; i < row; i++) {
        const row = document.createElement("tr")

        for (let j = 0; j < col; j++) {
            const cell = document.createElement("td")
            if (i == 0 && j == 0) {
                // Create "Runden" cell
                const cellText = document.createTextNode("Runden")
                cell.appendChild(cellText)
            } else if (i == 0 && j != 0) {
                // Create cells with player names in first row
                const cellText = document.createTextNode(playerNames[j])
                cell.appendChild(cellText)
            } else if (i != 0 && j == 0) {
                // Create round counter cells
                const cellText = document.createTextNode(String(i))
                cell.appendChild(cellText)
            } else {
                // Create rest of the cells
                cell.contentEditable = "true"
            }
            row.appendChild(cell)
        }
        tblBody.appendChild(row)
    }
    tbl.appendChild(tblBody)
    document.body.appendChild(tbl)

    addSumRowToTable(col)

    addEventListenerToTableDataCells()
    
    displayEventCardsButton()
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


function displayEventCardsButton() {
    let eventCardButton = document.getElementById("event_cards")

    if (eventCardButton) {
        eventCardButton.style.display = "block"
    }

}

