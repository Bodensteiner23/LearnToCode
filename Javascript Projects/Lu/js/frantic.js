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
    location.href = "frantic_event_cards.html"

}

