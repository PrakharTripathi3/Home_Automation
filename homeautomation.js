function bulb1onfunction(){
    
document.getElementById("device1off").style.display="none";
document.getElementById("device1on").style.display="block";
document.getElementById("off1").style.display="none";
document.getElementById("on1").style.display="block";
handleCover();
}
function bulb1offfunction() {
    
    document.getElementById("device1off").style.display = "block";
    document.getElementById("device1on").style.display = "none";
    document.getElementById("off1").style.display = "block";
    document.getElementById("on1").style.display = "none";
    handleCover();
}

function bulb2onfunction(){
   
document.getElementById("device2off").style.display="none";
document.getElementById("device2on").style.display="block";
document.getElementById("off2").style.display="none";
document.getElementById("on2").style.display="block";
handleCover();

}
function bulb2offfunction() {
   
    document.getElementById("device2off").style.display = "block";
    document.getElementById("device2on").style.display = "none";
    document.getElementById("off2").style.display = "block";
    document.getElementById("on2").style.display = "none";
    handleCover();

}


function fanonfunction(){
  
document.getElementById("device3off").style.display="none";
document.getElementById("device3on").style.display="block";
document.getElementById("off3").style.display="none";
document.getElementById("on3").style.display="block";

}
function fanofffunction() {
   
    document.getElementById("device3off").style.display = "block";
    document.getElementById("device3on").style.display = "none";
    document.getElementById("off3").style.display = "block";
    document.getElementById("on3").style.display = "none";
    

}

function handleCover() {
    var device1state = document.querySelector("#device1off");
    var device2state = document.querySelector("#device2off");
    var coverOpacity = document.getElementById("overlay");

    if (device1state.style.display === "none" && device2state.style.display === "block") {
        coverOpacity.style.backgroundColor = "rgba(0,0,0,0.6)"; // One device on
    } 
    else if (device1state.style.display === "block" && device2state.style.display === "none") {
        coverOpacity.style.backgroundColor = "rgba(0,0,0,0.6)"; // One device on
    } 
    else if (device1state.style.display === "none" && device2state.style.display ==="none") {
        coverOpacity.style.backgroundColor = "rgba(0,0,0,0)"; // Both devices on
    } 
    else {
        coverOpacity.style.backgroundColor = "rgba(0,0,0,0.9)"; // Both devices off
    }
}