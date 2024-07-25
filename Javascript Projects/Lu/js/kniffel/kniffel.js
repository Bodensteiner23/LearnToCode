/* ============================= Variables ============================ */
const playerCountButton = document.getElementById("player_count")

/* ============================= Functions ============================ */


function initEventListeners() {
    
    if (playerCountButton) {
        playerCountButton.addEventListener("click", playerCountButtonClicked)
    }
}

initEventListeners()


function playerCountButtonClicked() {
    const heading = document.getElementById("player_count_heading")
    let tableCols = null
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

    // ToDo: Handover to frantic_table file
    sessionStorage.setItem("tableCols", JSON.stringify(tableCols))
    sessionStorage.setItem("playerNames", JSON.stringify(playerNames))

    // Open next page
<<<<<<< HEAD
    window.location.href = "kniffel_table.html"
}




=======
    window.location.href = "frantic_table.html"
}


function displayEventCardsButton() {
    let eventCardButton = document.getElementById("event_cards")

    if (eventCardButton) {
        eventCardButton.style.visibility = "visible"
        eventCardButton.addEventListener("click", eventCardsButtonClicked)
    }
}


function eventCardsButtonClicked() {
    // Open event card subpage
    location.href = "kniffel_table.html"

}

>>>>>>> ef52c7bb298a1faed916918bd8f9e9658e97e063
