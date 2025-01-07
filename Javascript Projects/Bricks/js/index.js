const playingField = document.getElementById("playingField");

let start_game = false;

window.addEventListener("load", (event) => {
  testFunction();
});

function testFunction() {
  const playingField = document.getElementById("playingField");
  const para = document.createElement("h1");
  para.textContent = "Test";
  playingField.appendChild(para);
}

function startGame() {
  const startButton = document.getElementById("startGameButton");
  startButton.remove();

  start_game = true;
}

function main() {
  if (start_game) {
    console.log("Test");
    start_game = false;
  }
}

// Set Interval to 60 Hz
setInterval(main, 16); // 16ms ~ 60 Hz
