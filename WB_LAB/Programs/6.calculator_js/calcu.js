function performop(op) {
    var result = 0;
    var n1=parseInt(document.getElementById("num1").value);
    var n2=parseInt(document.getElementById("num2").value);
    if (op=="+") {
    var result=n1+n2 ;
    }
    else if(op=="-") {
    var result=n1-n2;
    }
    else if(op=="*") {
    var result=n1*n2;
    }
    else
    {
    var result=n1/n2
    }
    document.getElementById("res").value=result;
    }
    