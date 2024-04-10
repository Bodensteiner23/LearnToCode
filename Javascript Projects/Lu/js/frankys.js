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
    getPlayerCount(userPlayerCount)
}


function getPlayerCount(_playerCount) {
    let playerCount = _playerCount
    
    return playerCount
}







function createTable(row, col) {
    let body = document.body
    let tbl = document.createElement("table")
    tbl.style.width = "200px"
    tbl.style.border = "1px solid black"

    for (let i = 0; i < row; i++){
        let tr = tbl.insertRow()
        for (let j = 0; i < col; i++) {
            let td = tr.insertCell()
            td.appendChild(document.createTextNode("${i}, ${j}"))
            td.style.border = "1px solid black"
        }
    }
    body.appendChild(tbl)

}


createTable(3, 5)