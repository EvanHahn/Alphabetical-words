fs = require 'fs'

String::isAlphabetical = ->
	return true if @length < 2
	for i in [1..(@length - 1)]
		return false if @[i] < @[i - 1]
	return true

fs.readFile 'words.txt', (err, data) ->

	if err
		console.error 'Cannot open words.txt.'
		process.exit 1

	words = data.toString('ascii').split('\n')
	alphacount = 0

	for word in words
		word = word.trim()
		if word.length and word.isAlphabetical()
			alphacount++
			console.log word

	console.log ''
	console.log "#{alphacount} are alphabetical out of #{words.length} (#{(alphacount / words.length) * 100} percent)"
