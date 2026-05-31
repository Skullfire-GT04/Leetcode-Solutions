
const asteroidsDestroyed = (mass, asteroids) => {

    asteroids.sort((a, b) => a - b);
    let curr_mass = mass;
    for(let i = 0; i < asteroids.length; i++){
        if(asteroids[i] > curr_mass) return false;
        curr_mass += asteroids[i];
    }
    return true;
}


console.log(asteroidsDestroyed(5, [4, 9, 23, 4]));