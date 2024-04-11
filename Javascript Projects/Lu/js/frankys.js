/* ============================= Variables ============================ */
const playerCountButton = document.getElementById("player_count")
const heading = document.getElementById("player_count_heading")


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

    let tableCols = playerNames.length

    createTable(21, tableCols, playerNames)
}


function getPlayerCount(_playerCount) {
    let playerCount = _playerCount
    
    return playerCount
}

function getPlayerNames(_playerNames) {
    let playerNames = _playerNames

    return playerNames

}


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
                const cellText = document.createTextNode("Runden")
                cell.appendChild(cellText)
            } else if (i == 0 && j != 0) {
                const cellText = document.createTextNode(playerNames[j])
                cell.appendChild(cellText)
            } else if (i != 0 && j == 0) {
                const cellText = document.createTextNode(i)
                cell.appendChild(cellText)
            } else {
                cell.contentEditable = "true"
            }
            row.appendChild(cell)

        }
        tblBody.appendChild(row)

    }

    tbl.appendChild(tblBody)
    document.body.appendChild(tbl)

}

// createTable([1,2,3, 7, 9], [10,11,12, 10])


