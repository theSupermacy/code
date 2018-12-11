var {
    createQueue
} = require('./../queue')
var assert = require('assert')

describe('it should represent the queue ', function(){
    let outerScope = this
    beforeEach(function(){
        const queue = createQueue()
        outerScope.queue = queue
    })
    
    it('should have all the necessary of the queue', function(){
        const queue = outerScope.queue
        assert.equal(typeof queue.enqueue, 'function', 'type of enqueue should be function')
        assert.equal(typeof queue.dequeue, 'function', 'should contain dequeue function')
        assert.equal(typeof queue.peek, 'function', 'should contain peek function to see the current element')
        assert.equal(typeof queue.isEmpty, 'function', 'type of isEmpty should be function')
        assert.equal(typeof queue.currentLength, 'function', 'should contain  currentLength')
    })
    it('current size of queue should be zero and isEmpty should be true', function(){
        const queue = outerScope.queue
        assert.equal(queue.currentLength(), 0)
        assert.equal(queue.isEmpty(), true)
    })
    it('should insert in the queue', function(){
        const newElement = 5
        outerScope.queue.enqueue(newElement)
        assert.equal(outerScope.queue.currentLength(),1)
        assert.equal(outerScope.queue.peek(), 5)
        assert.equal(outerScope.queue.isEmpty(), false)
        outerScope.queue.enqueue(6)
        assert.equal(outerScope.queue.currentLength(),2)
        assert.equal(outerScope.queue.peek(), 5)
        assert.equal(outerScope.queue.isEmpty(), false) 
       })
    it('should dequeue from the queue', function(){
        const queue = outerScope.queue
        const newElement = 5
        outerScope.queue.enqueue(newElement)
        assert.equal(outerScope.queue.currentLength(),1)
        assert.equal(outerScope.queue.peek(), 5)
        assert.equal(outerScope.queue.isEmpty(), false)
        outerScope.queue.enqueue(6)
        assert.equal(outerScope.queue.currentLength(),2)
        assert.equal(outerScope.queue.peek(), 5 )
        assert.equal(outerScope.queue.isEmpty(), false) 
        queue.dequeue()
        assert.equal(queue.currentLength(),1)
        assert.equal(queue.peek(), 6)
        assert.equal(queue.isEmpty(), false)
        queue.dequeue()
        assert.equal(queue.currentLength(),0)
        assert.equal(queue.isEmpty(), true)
    })
})