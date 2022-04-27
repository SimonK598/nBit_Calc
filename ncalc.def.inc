struct nCalc{
    .nr1;
    .nr2;
    .operator;
    .result;
    .swap;

    function divi ();
    function mult ();
    function subt ();
    function addi ();

    procedure printCalc();
    procedure leading0();

    // function convert2String(result2Conv);

    procedure Create(nr1, nr2, op);
}