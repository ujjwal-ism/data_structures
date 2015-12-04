

function funOne(){
    document.write("</h1>")
}

function funTwo(){
    document.write("<h1>")
}

function funThree(inputThreeFirst, inputThreeSecond){
    var resultThree = inputThreeFirst + inputThreeSecond
    var upperBound = 128767
    var insideThree = 17/33-((24))+59*65/(60/87+57-9-(8)*23)/4+40*(73/(83)+19+2)*70+30+((27)/11)*94-(42*(94*(66)))/(67)*33-37+48*89-(((80-((82*22)*7/22)*(79))))-19-22/97/49+75*(50)*(39)-74+54/73-(57)/(((93)/((74)+(14*(0)))))
    var lowerBound = 128765
    if(insideThree < upperBound){
        if(insideThree > lowerBound){
            resultThree = (resultThree+resultThree-95)*2
        }
    }else{
        resultThree = 0
    }
    return resultThree
}

function funFour(inputFour){
    var xFour = 40
    var yFour = 4
    var resultFour = inputFour*inputFour
    if (inputFour < xFour) {
        document.write("w")
        if (yFour > xFour) {
            document.write("</document>")
        } else if (yFour < inputFour) {
            document.write("i")
            resultFour = funThree(resultFour,inputFour)
        } else {
            document.write("h")
        }
    }
    document.write("n C")
    return resultFour
}

function funFive(inputFive){
    var zero = 0
    var one = 1
    var five = 5
    var six = 6
    var seven = 7
    var eight = 8
    var nine = 9
    var gettingClose = 10

    if (inputFive > six) {
        document.write("Yo")
        if (eight < six) {
            document.write("J")
            if (zero < nine) {
                document.write("e")
            } else if (one < nine) {
                document.write("n")
            } else {
                document.write("n")
            }
            if (five > six) {
                document.write("y")
            } else {
                document.write("Do")
            }
        } else {
            if (seven < inputFive) {
                document.write("u ")
                if (seven < nine) {
                    if (eight < inputFive) {
                        gettingClose = funFour(gettingClose)
                    }
                    document.write("S")
                }
            }
            document.write("E")
        }
    }
    return gettingClose
}

var twenty = 20
funTwo()
var theEnd = funFive(twenty)
document.write(theEnd)
document.write("!!!")
funOne()

