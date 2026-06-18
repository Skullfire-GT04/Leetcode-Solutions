
const unit = 6;
const hour_unit = 0.5;
const angleClock = (hour, minute) => {
    let minute_angle = minute * unit % 360;
    if(!minute_angle) minute_angle = 360;
    let hour_angle = hour_unit * minute + (hour * unit * 5) % 360;
    return Math.min(Math.abs(minute_angle - hour_angle), Math.abs(360 - Math.abs(hour_angle - minute_angle)));
}


console.log(angleClock(1, 57));