
function multiply(a,b){
    var product = a*b
    return product
}

function printBlankLine(){
    document.write("<br/>")
}

function printNumber(number){
    document.write(number)
    printBlankLine()
}


var five = 5
var eleven = 11
var product = multiply(five, eleven)

printNumber(product)
