
function absoluteValue(value){
    var negated = 0-value

    if(negated > value){
        return negated
    }

    return value
}


function equal(a,b){
    var resultTrue = 1
    var resultFalse = 0
    var difference = a-b
    var absDifference = absoluteValue(difference)
    var epsilon = 0.00001
    if(absDifference < epsilon){
        return resultTrue
    }
    return resultFalse
}


var number = 5
var zero = 0
var n=15
var x=12
var result = equal(n,x)
var midPoint = 0.5
if(result < midPoint){
    if(number > zero){
        if(n<x) {
            document.write("shouldn't write this<br/>")
        }else if(zero < midPoint){
            document.write("The midPoint is: ")
            document.write(midPoint)
            document.write("<br/>")
        }else{
            document.write("shouldn't write this<br/>")
            document.write("The number is: ")
            document.write(number)
            document.write("<br/>")
        }
    }else{
        document.write("shouldn't write this<br/>")
    }
}else if(n>zero){
    document.write("shouldn't write this<br/>")
}
document.write("Zero is: ")
document.write(zero)
document.write("<br/>")
