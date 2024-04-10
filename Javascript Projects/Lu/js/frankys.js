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
    tblBody.id = "tableBody"


    // Creating cells
    for (let i = 0; i < row; i++) {
        const row = document.createElement("tr")
        row.id = "tableRow"

        for (let j = 0; j < col; j++) {
            const cell = document.createElement("td")
            cell.id = "tableCell"

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





// function createTable(row, col) {
//     let body = document.body
//     let tbl = document.getElementById("game_table")
//     if (tbl) {
//         tbl.style.width = "200px"
//         tbl.style.border = "1px solid black"

//     }

//     for (let i = 0; i < row; i++){
//         let tr = tbl.insertRow()
//         for (let j = 0; i < col; i++) {
//             let td = tr.insertCell()
//             td.appendChild(document.createTextNode("${i}, ${j}"))
//             td.style.border = "1px solid black"
//         }
//     }
//     body.appendChild(tbl)

// }


// createTable(3, 5)