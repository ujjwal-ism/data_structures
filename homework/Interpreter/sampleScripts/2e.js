function four(last){
    document.write("Hello from the fourth nested function call")
    document.write("<br/>")
    var lastly = last * last
    return lastly
}
function three(e,f,g){
    var resultThree = e+f*(g-3)
    resultThree = four(resultThree)
    return resultThree
}

function two(c,d){
    var resultTwo = 2
    resultTwo = three(c,d,resultTwo)
    document.write("resultTwo: ")
    document.write(resultTwo)
    document.write("<br/>")
    return resultTwo
}
function one(a,b){
    var adding = a + b
    var resultOne = two(a,adding)
    resultOne = resultOne/2.5
    return resultOne
}


var five = 5
var eleven = 11
var result = one(five, eleven)
document.write("Final Result: ")
document.write(result)