sleep = function(a)
	local sec = tonumber(os.clock() + a);
	while(os.clock() < sec) do
	end
end	

writeOut = function()
	JSON = (loadfile "JSON.lua")();

	local test1K = "I am no.1";
	local test1V = 1;

	testTable = {test1K, test1V};

	local testJson = JSON:encode(testTable);

	file = io.open ("test.json", "a");
	io.output(file);

	io.write(testJson);
	io.close(file);
end

readIn = function()
	local file = io.open("test.json", "r")
	
	io.input(file)
	
	local tableVar = {}
	
	tableVar = io.read(file)
	
	io.close(file)
	
	return tableVar
end

main = function()
{
	writeOut()
	return readIn()
}