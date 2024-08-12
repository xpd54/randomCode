// spawn(command[, args], opetions)
// command: the command which is to be run
/* options: take an object with following 
    cwd: the current working directory 
    env: the environment key-value pairs bydefault it's process.env
    argv0: the vlaue of argument argv[0] sent to the child process. this will be set to command if not specified
    stdio: the child process stdio
    detached: boolean if it will run independently of it's parent process
    uid: the user identity of the process
    git: the group id of the process
    serialization:
    shell:
    timeout: maximum amout of time the process is allowed to run
*/


const {spawn} = require('child_process')
const lsProcess = spawn('ls', {cwd: '../', argv0:'-a'})

lsProcess.stdout.on('data', data => {
    console.log(`stdout: ${data}`)
})

lsProcess.stderr.on('data', (data) => {
    console.log(`stdout: ${data}`)
})

lsProcess.on('exit', code => {
    console.log('Process ended with ', code);
})

console.log('I a here already')