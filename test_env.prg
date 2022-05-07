include("std.inc");
include ("conv.inc");
include ("./ncalc.gpp.inc");
include ("./ncalc.def.inc");
include ("./ncalc.fnc.inc");


procedure main(){

    str = <31 00>;
    echo "str: "# form("%C", str) # endl;
    echo "str: "# str # endl;
    // echo "maxi: " # form("%d", maxi("10", "30"));

}