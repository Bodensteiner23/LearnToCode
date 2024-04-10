/* ============================= Variables ============================ */
const playerCountButton = document.getElementById("player_count")
const heading = document.getElementById("player_count_heading")
// const gameTable = document.getElementById("game_table")


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
    getPlayerCount(userPlayerCount)
}


function getPlayerCount(_playerCount) {
    let playerCount = _playerCount
    
    return playerCount
}


function createTable(row, col) {
    const tbl = document.createElement("table")
    tbl.id = "table"
    const tblBody = document.createElement("tbody")


    // Creating cells
    for (let i = 0; i < row; i++) {
        const row = document.createElement("tr")

        for (let j = 0; j < col; j++) {
            const cell = document.createElement("td")

            const cellText = document.createTextNode("Test" + i)
            cell.appendChild(cellText)
            row.appendChild(cell)

        }
        tblBody.appendChild(row)

    }

    tbl.appendChild(tblBody)
    document.body.appendChild(tbl)

}

createTable(9, 3)


