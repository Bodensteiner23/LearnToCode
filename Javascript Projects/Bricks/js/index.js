const playingField = document.getElementById("playingField");

let start_game = false;

window.addEventListener("load", (event) => {
  addCanvas();
  initGame();
});

function addCanvas() {
  const gameCanvas = document.createElement("canvas");
  gameCanvas.id = "gameCanvas";
  gameCanvas.width = 1500;
  gameCanvas.height = 700;

  const ctx = gameCanvas.getContext("2d");
  ctx.fillStyle = "blue";
  ctx.fillRect(100, 100, 500, 100);

  playingField.appendChild(gameCanvas);
}

function initGame() {}

function startGame() {
  const startButton = document.getElementById("startGameButton");
  startButton.remove();

  start_game = true;
}

function main() {
  if (start_game) {
    start_game = false;
  }
}

// Set Interval to 60 Hz
setInterval(main, 16); // 16ms ~ 60 Hz
