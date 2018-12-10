const createQueue = function() {
    let array = []
    return {
        enqueue(ele){
            array.unshift(ele)
        },
        dequeue(){
            array.shift()
        },
        isEmpty(){
            return array.length === 0 
        },
        peek(){
            return array
        },
        currentLength(){
            return array.length
        }
    }
}

module.exports = {
    createQueue
}