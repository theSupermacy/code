const createQueue = function() {
    let array = []
    return {
        enqueue(ele){
            array.unshift(ele)
        },
        dequeue(){
            array.pop()
        },
        isEmpty(){
            return array.length === 0 
        },
        peek(){
            return array[array.length - 1]
        },
        currentLength(){
            return array.length
        }
    }
}

module.exports = {
    createQueue
}