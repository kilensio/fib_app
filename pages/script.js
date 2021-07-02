let text = document.querySelector('strong')
let btn = document.querySelector('button')

const nextFib = async () => {
    let res = await fetch('/fib')
    let fib = await res.json()
    text.innerText = fib
}

btn.addEventListener('click', nextFib)