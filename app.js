const http = require('http')
const fs = require('fs')

const fib = require('bindings')('fib')

const PORT = 3000
const FIB = 'fib'
const INDEX = 'index.html'

http.createServer((request, response) => {
    const filePath = request.url.substr(1) || INDEX

    if (filePath == FIB) {
        response.end(fib.get())
    } else {    
        fs.access(`pages/${filePath}`, fs.constants.R_OK, err => {
            if (err) {
                response.statusCode = 404
                response.end('Page not found')
            } else {
                fib.clear()
                fs.createReadStream(`pages/${filePath}`).pipe(response)
            }
        })
    }
}).listen(PORT, () => {console.log(`Server started on port ${PORT}`);})