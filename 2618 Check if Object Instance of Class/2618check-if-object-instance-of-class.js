/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj==null||typeof classFunction!=="function"){
        return false;
    }
    let proto=Object.getPrototypeOf(obj);
    // console.log(classFunction.prototype);
    // while(proto!=null){
    //     console.log(proto);
    //     proto=Object.getPrototypeOf(proto);
    // }
    while(proto!=null){
        if(proto==classFunction.prototype)return true;
        proto=Object.getPrototypeOf(proto);
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */