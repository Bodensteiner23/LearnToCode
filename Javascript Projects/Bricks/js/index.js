window.addEventListener("load", (event) => {
  testFunction();
});

function testFunction() {
  const playingField = document.getElementById("playingField");
  const para = document.createElement("h1");
  para.textContent = "Test";
  playingField.appendChild(para);
  console.log("test");
}

function startGame() {
  return true;
}
