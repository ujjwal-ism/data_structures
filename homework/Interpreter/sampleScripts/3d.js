var x=10
var y=20
var z=30
if(x<y) {
    document.write("x is less than y<br/>")
    if (y < z) {
        document.write("y is less than z<br/>")
    } else if(x<z) {
        document.write("Why is this printing?<br/>")
    }else{
        document.write("Why is this printing?<br/>")
    }
} else{
    document.write("Why is this printing?<br/>")
}