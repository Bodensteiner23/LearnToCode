# Projekt Console Calculator

## Ziel 
Entwickle eine erweiterte Taschenrechner-Anwendung in Python, die über die grundlegenden arithmetischen Operationen hinausgeht. Dein Taschenrechner sollte in der Lage sein, komplexe mathematische Ausdrücke zu verarbeiten, Funktionen zu unterstützen und eine benutzerfreundliche Konsoleninteraktion zu bieten.

## Grundfunktionen:
### Ausdrucksauswertung: 
Der Taschenrechner sollte in der Lage sein, komplexe mathematische Ausdrücke, einschließlich Klammerung und Standardoperationen (Addition, Subtraktion, Multiplikation, Division), korrekt auszuwerten.

### Unterstützung mathematischer Funktionen:
Integriere mathematische Funktionen wie Sinus, Kosinus, Tangens, Logarithmus, Exponentialfunktionen und Quadratwurzeln.

### Variable und Konstanten:
Ermögliche Benutzern, Werte in Variablen zu speichern und später im Programm auf diese zuzugreifen. Definiere auch wichtige mathematische Konstanten wie Pi und e.

## Fortgeschrittene Funktionen
### Funktionsplotter:
Implementiere eine Funktion, die mathematische Funktionen grafisch darstellt. Dies könnte in einer einfachen Form geschehen, wie ASCII-Kunst in der Konsole, oder durch eine Integration mit einer Bibliothek zur Grafikerstellung.

### Gleichungslöser:
Füge eine Funktion hinzu, die lineare und quadratische Gleichungen löst und die Lösungen ausgibt.

### Einheitenkonverter:
Implementiere eine Funktion zur Umrechnung zwischen verschiedenen Maßeinheiten (z.B. von Kilometern in Meilen, von Kilogramm in Pfund).

## Benutzeroberfläche und Benutzererfahrung:
### Interaktive Benutzeroberfläche:
Entwickle eine benutzerfreundliche Konsolenoberfläche. Anstatt eines einmaligen Durchlaufs sollten Benutzer in der Lage sein, mehrere Berechnungen nacheinander durchzuführen und zwischen verschiedenen Funktionen über ein Menü zu wählen.

### Verlauf und Speicher:
Integriere eine Verlaufsfunktion, die es dem Benutzer ermöglicht, vorherige Berechnungen einzusehen. Füge auch eine Speicherfunktion hinzu, ähnlich den M+ und M- Funktionen herkömmlicher Taschenrechner.

### Fehlerbehandlung und Validierung: 
Stelle sicher, dass dein Programm angemessen auf Benutzereingabefehler reagiert, wie falsche Formate oder ungültige Operationen, und leite den Benutzer entsprechend an.


## Pseudocode
**Programm ErweiterterTaschenrechner**

    Funktion Hauptmenü()
        Zeige "Erweiterter Taschenrechner"
        Zeige "Wähle eine Option:"
        Zeige "1. Berechne Ausdruck"
        Zeige "2. Löse Gleichung"
        Zeige "3. Funktionsplotter"
        Zeige "4. Einheitenkonverter"
        Zeige "5. Beenden"
        Wahl = Benutzereingabe()
        Wähle entsprechend der Wahl

    Funktion BerechneAusdruck()
        Zeige "Gib einen mathematischen Ausdruck ein:"
        Ausdruck = Benutzereingabe()
        Ergebnis = EvaluiereAusdruck(Ausdruck)
        Zeige Ergebnis

    Funktion EvaluiereAusdruck(Ausdruck)
        // Implementiere einen Parser und Auswerter für den Ausdruck
        // Unterstütze Variablen, Klammern und mathematische Funktionen
        Rückgabe Berechnetes Ergebnis

    Funktion LöseGleichung()
        Zeige "Gib eine Gleichung ein:"
        Gleichung = Benutzereingabe()
        Lösungen = FindeLösungen(Gleichung)
        Zeige Lösungen

    Funktion Funktionsplotter()
        Zeige "Gib eine mathematische Funktion ein:"
        Funktion = Benutzereingabe()
        ZeichneFunktion(Funktion)

    Funktion Einheitenkonverter()
        Zeige "Wähle die Einheiten zum Konvertieren:"
        // Implementiere Logik für Einheitenkonversion

    // Hauptlogik
    Wiederhole
        Hauptmenü()
    Bis Benutzer Beenden wählt

**Ende Programm**
