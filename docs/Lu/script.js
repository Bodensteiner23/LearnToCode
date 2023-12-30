function openOverlay() {
  document.getElementById("overlay").style.display = "block";
}

function closeOverlay() {
  document.getElementById("overlay").style.display = "none";
}

document.getElementById("openOverlayBtn").addEventListener("click", openOverlay);

function createTable() {
  const playerCount = parseInt(document.getElementById("playerCount").value);
  const table = document.getElementById("scoreTable");
  const thead = table.querySelector("thead");
  const tbody = table.querySelector("tbody");
  const tfoot = table.querySelector("tfoot");

  
  
  // Lösche vorhandene Tabelleninhalte
  thead.innerHTML = "";
  tbody.innerHTML = "";
  tfoot.innerHTML = "";
  
  // Füge Spieler-Namen in den Header ein
  const headerRow = document.createElement("tr");
  for (let i = 0; i < playerCount + 1; i++) {
    const cell = document.createElement("th");
    if (i === 0) {
      cell.textContent = "Runde";
    } else {
      const playerName = prompt(`Geben Sie den Namen für Spieler ${i} ein:`);
      cell.textContent = playerName || `Spieler ${i}`;
    }
    headerRow.appendChild(cell);
  }
  thead.appendChild(headerRow);

  // Füge leere Zeilen in die Tabelle ein
  for (let i = 0; i < 18; i++) {
    const row = document.createElement("tr");

    for (let j = 0; j <= playerCount; j++) {
      const cell = document.createElement(j === 0 ? "th" : "td");
      const input = document.createElement("input");
      input.type = "text";
      input.classList.add(j === 0 ? "name-input" : "score-input");

      // Wenn wir uns in der Rundenspalte befinden, nummerieren wir die Zellen
      if (j === 0) {
        input.value = i + 1;
        input.readOnly = true;
        cell.classList.add("round-cell"); // Fügt die Klasse "round-cell" hinzu
      }
      cell.appendChild(input);
      row.appendChild(cell);
    }
    
    tbody.appendChild(row);
  }

  // Füge Summenzeile ein
  const sumRow = document.createElement("tr");

  for (let j = 0; j <= playerCount; j++) {
    const cell = document.createElement(j === 0 ? "th" : "td");
    cell.classList.add("sum-cell");
    sumRow.appendChild(cell);
  }

  tfoot.appendChild(sumRow);

   // Verstecke das Label und die Eingabe für die Anzahl der Spieler
   const playerCountLabel = document.querySelector('label[for="playerCount"]');
   const playerCountInput = document.getElementById("playerCount");
   const playerSetButton = document.querySelector('button[onclick="createTable()"]');
 
   if (playerCountLabel && playerCountInput && playerSetButton) {
     playerCountLabel.style.display = "none";
     playerCountInput.style.display = "none";
     playerSetButton.style.display = "none";
   }
 
   // Füge Event Listener für die Berechnung der Summen hinzu
   const inputFields = document.querySelectorAll(".score-input");
   inputFields.forEach(function (input) {
     input.addEventListener("input", updateSums);
   });
}

function updateSums() {
  const sumRow = document.querySelector(".sum-row");
  const cells = sumRow.querySelectorAll(".sum-cell");

  cells.forEach(function (cell, columnIndex) {
    let sum = 0;

    document.querySelectorAll(`#scoreTable tbody td:nth-child(${columnIndex + 1}) input`).forEach(function (input) {
      const value = parseInt(input.value) || 0;
      sum += value;
    });

    // Setze den Textinhalt auf einen leeren String, wenn die Summe 0 ist
    cell.textContent = sum !== 0 ? sum : '';
  });
}


