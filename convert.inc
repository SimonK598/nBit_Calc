include ("std.inc")

// scan()
function convd(convert){
    return scan("%d", convert);
}
function convc(convert){
    return scan("%C", convert);
}
function convf(convert){
    return scan("%f", convert);
}
function convx(convert){
    return scan("%x", convert);
}

//-------------------------------------------------------

// form()
function sconvc(convert){
    return form("%C", convert);
}
function sconvi(convert){
    return form("%i", convert);
}
function sconvu(convert){
    return form("%u", convert);
}
function sconvf(convert){
    return form("%f", convert);
}