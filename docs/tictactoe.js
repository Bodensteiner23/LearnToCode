/* ============================= Variables ============================ */
const heading = document.getElementById("heading");
const buttons = document.querySelectorAll(".buttons");
const startButton = document.getElementById("start_game_button");
const newGameButton = document.getElementById("start_new_game_button");

let playerOneTurn = null;
let turnCounter = null;

let playingFielddArray = [0, 0, 0,
                          0, 0, 0,
                          0, 0, 0]

/* ============================= Functions ============================ */
/* ========================= Button Functions ========================= */
/**
 *  @brief  Initialization of all button event listeners
 */
function initButtonEventListeners() {
    // Start the game Button
    if (startButton) {
        startButton.addEventListener("click", startButtonClicked);
    }

    // Game field buttons
    for(let i = 0; i < buttons.length; i++) {
        buttons[i].addEventListener("click", buttonClicked)
        // @ts-ignore
        buttons[i].disabled = true;
    }

    // New Game Button
    if (newGameButton) {
        newGameButton.addEventListener("click", newGameButtonClicked)
    }
}

/**
 *  @brief  Logic if start button is clicked
 */
function startButtonClicked() {
    if (startButton) {
        startButton.style.display = "none";
    }
    //Set Player One Turn to True
    playerOneTurn = true;
    updateHeading("Player 1 turn");

    enableDisableButtons("enable")
}

/**
 *  @brief  Logic if game-field buttons are clicked. Handles Game Structure.
 * 
 *  @param  event Object that contains information about the button click
 */
function buttonClicked(event) {
    // Check if Button has already been clicked
    if (event.target.hasAttribute('data-clicked')) {
        // The button has been clicked before

        return;
    } else {
        // The button has not been clicked before
        event.target.setAttribute('data-clicked', 'true');
        
        updatePlayingField(event.target.id, playerOneTurn)

        let gameOver = checkWin(playerOneTurn)
        
        wonGame(gameOver, playerOneTurn)
    
        addImageToButton(event, playerOneTurn)
        
        // Check if game is over
        if (gameOver) {
            enableDisableButtons("disable")
        } else {
            if (playerOneTurn) {
                updateHeading("Player 1 turn")
            } else {
                updateHeading("Player 2 turn")
            }
        }

        turnCounter += 1;
        checkDraw(gameOver, turnCounter)
    }
}

/**
 *  @brief  Enable or disable game-field buttons
 * 
 *  @param  state State the buttons should be changed to: "enable"/"disable"
 */
function enableDisableButtons(state) {
    for (let i = 0; i < buttons.length; i++) {
        if (state == "enable") {
            // @ts-ignore
            buttons[i].disabled = false;    
        } else {
            // State is disable
            // @ts-ignore
            buttons[i].disabled = true; 
        }
    }
}

/**
 *  @brief  Add Image class to the button that was clicked
 * 
 *  @param  event Object that contains information about the button click
 *  @param  playersTurn True if Player1 / False if Player2
 */
function addImageToButton(event, playersTurn) {
    if (playersTurn) {
        event.target.classList.add("cross");
        
        playerOneTurn = false
    } else {
        // Check if button is already clicked
        if (event.target.classList.contains("cross")) {
            // Skip
        } else {
            event.target.classList.add("circle");
        }
        playerOneTurn = true;
    }
}

/**
 *  @brief  Logic if the new game button is clicked. Resets all states for new game
 */
function newGameButtonClicked() {
    // Game field buttons
    enableDisableButtons("enable")
    for(let i = 0; i < buttons.length; i++) {
        buttons[i].removeAttribute("data-clicked")
        buttons[i].classList.remove("cross")
        buttons[i].classList.remove("circle")
    }

    if (newGameButton) {
        newGameButton.style.display = "none"
    }
    
    updateHeading("Player 1 turn")

    playerOneTurn = true

    turnCounter = null
    
    playingFielddArray = [0, 0, 0,
                          0, 0, 0,
                          0, 0, 0]
}


/* ================================ Text ============================== */
/**
 *  @brief  Updates the Heading of the App
 * 
 *  @param  text Text that should be displayed
 */
function updateHeading(text) {
    if (heading) {
        heading.textContent = text;
    }
}
    

/* ============================= Game Logic =========================== */
/**
 *  @brief  Checks what Player Turn it is and returns the symbol of that player
 * 
 *  @param  playerOneTurn True if Player1 / False if Player2
 */
function setPlayerTurn(playerOneTurn) {
    let playerSymbol = 0
    
    if (playerOneTurn) {
        playerSymbol = 1
    } else {
        playerSymbol = 2
    }

    return playerSymbol
}

/**
 *  @brief  Updates playing field array, that represents the playing field for the user
 * 
 *  @param  buttonClicked Id of the Button that was clicked
 *  @param  playerOneTurn True if Player1 / False if Player2
 */
function updatePlayingField(buttonClicked, playerOneTurn) {
    // Check which Player is playing
    let playerSymbol = setPlayerTurn(playerOneTurn)

    switch(buttonClicked) {
        case "top_left":
            playingFielddArray[0] = playerSymbol
            break;
        case "top_middle":
            playingFielddArray[1] = playerSymbol
            break;
        case "top_right":
            playingFielddArray[2] = playerSymbol
            break;
        case "middle_left":
            playingFielddArray[3] = playerSymbol
            break;       
        case "middle_middle":
            playingFielddArray[4] = playerSymbol
            break
        case "middle_right":
            playingFielddArray[5] = playerSymbol
            break
        case "bottom_left":
            playingFielddArray[6] = playerSymbol
            break
        case "bottom_middle":
            playingFielddArray[7] = playerSymbol
            break
        case "bottom_right":
            playingFielddArray[8] = playerSymbol
            break
    }

}

/**
 *  @brief  Checks for winning conditions of TicTacToe Game
 * 
 *  @param  playerOneTurn True if Player1 / False if Player2
 * 
 *  @retval True if game is over / False if not
 */
function checkWin(playerOneTurn) {
    let playerSymbol = setPlayerTurn(playerOneTurn) 
    let gameOver = false
    
    for (let i = 0; i < 3; i++) {
        // Test horizontal fields
        let verticalFields = [i, i + 3, i + 6]
        if (verticalFields.every(index => playingFielddArray[index] === playerSymbol)) {
            gameOver = true
        }   // Should be ok
        
        // Test vertical fields
        let horizontalFields = [i*3, i*3 + 1, i*3 + 2]
        if (horizontalFields.every(index => playingFielddArray[index] === playerSymbol)) {
            gameOver = true
        }   // Should be okay
        
    }
    // Test diagonall fields
    let diagonallFieldsLeftToRight = [0, 4, 8]
    let diagonallFieldsRightToLeft = [2, 4, 6]
    
    if (diagonallFieldsRightToLeft.every(index => playingFielddArray[index] === playerSymbol)) {
        gameOver = true
    } else if (diagonallFieldsLeftToRight.every(index => playingFielddArray[index] === playerSymbol)) {
        gameOver = true
    }

    return gameOver
}

/**
 *  @brief  Display winning message and new game Button
 * 
 *  @param  gameOver True if game is over / False if not
 *  @param  playerOneTurn True if Player1 / False if Player2
 */
function wonGame(gameOver, playerOneTurn) {

    let player = setPlayerTurn(playerOneTurn)

    if (gameOver) {
        updateHeading("Player " + player + " has won!")
        
        // Display new Game Button
        if (newGameButton) {
            newGameButton.style.display = "flex"
        }
    }
}

/**
 *  @brief  Checks if the game is in a draw state
 * 
 *  @param  gameOver True if game is over / False if not
 *  @param  turnCounter Counter for how many rounds have already been played
 */
function checkDraw(gameOver, turnCounter){
    
    if (!gameOver && turnCounter == 9) {
        updateHeading("Draw! Nobody has won!")

        // Display new Game Button
        if (newGameButton) {
            newGameButton.style.display = "flex"
        }
    }

}

// Main Function
function main() {

    // Init 
    initButtonEventListeners()


}

// Calling main Function
main()
