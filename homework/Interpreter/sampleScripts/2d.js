function printBlankLine(){
    document.write("<br/>")
}

function printSumNumbers(a,b){
    document.write(a)
    printBlankLine()
    document.write(b)
    var c = a+b
    return c
}

var five = 5
var eleven = 11
var sum = printSumNumbers(five, eleven)
document.write("<br/>")
document.write(sum)