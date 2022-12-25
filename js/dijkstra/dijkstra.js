let fs = require('fs');
let arg = process.argv;
let input = fs.readFileSync(arg[2]);
input = input.toString(); 

let output = '';
let stack = new Array();

function prioritize(elem){
	if (elem == '(' || elem == ')')
		return 0
	else if (elem == '+' || elem == '-')
		return 1
	else if (elem == '*' || elem == '/')
		return 2
	else if (elem == '^')
		return 3
	else return -1 
}

for (let i = 0; i<input.length; i++){
	let elem = input[i];

    if (elem == ' ')
        continue;
	else if (prioritize(elem) == -1)
		output += elem;
	else if (elem == '(')
		stack.push('(');
	else if (elem == ')'){
		while (stack[stack.length - 1] != '(')
			output += stack.pop();
		stack.pop();
	}
	else {
		while (prioritize(elem) <= prioritize(stack[stack.length - 1]))
			output += stack.pop();
		stack.push(elem);
	}
}

stackLen = stack.length;
if (stackLen > 0){
	for (i = 0; i < stackLen; i++){
		output += stack.pop();
	}
}

console.log(output);