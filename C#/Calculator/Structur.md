# Calculator

## 1.0 User Input

### 1.1 Number clicked
1. Check if Number is valid **DONE**
2. Check if _reservedNumber1 already has a value 
#### 1.1.1 Case 1: _reservedNumber1 has no value
Save the Number into _reservedNumber1
#### 1.1.2 Case 2: _reservedNumber1 already has a value
1. Execute the Operation that is stored in _operator and save the result in _reservedNumber
2. Reset _userNumber

### 1.2 Case 1: More Numbers are clicked
1. Add Number to the already existing number in the Label
### 1.2 Case 2: Operator clicked
1. Check if Operator is valid
2. Readout Number in the Label and store it in a _reservedNumber2
3. Output _reservedNumber1 + the operater
4. Label should stay the same until you click the next Number. Then it should work like 1.1

## 1.3 Equal Operator is clicked
Execute remaining Operation that is stored in Operator
















# Program Sequence

_userNumber = 1  
outputData = 1  
_userNumber = 2  
outputData += 2 -> _userNumber = 12  
operater.clicked = "+"  
**_userNumber needs to be cleared**  
**store outputData in _reservedNumber1** DONE  
_operator = "+"  
outputData = outputData + _operator  


_userNumber = 5  
outputData = 5  
_userNumber = 8  
outputData += 58 -> _userNumber = 58  

operator.clicked = "+"  
