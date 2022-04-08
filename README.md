# CChain
Proof-of-work based blockchain in C++

Started April 6, 2022

Goal:
To create a relatively inexpensive, 'lite' blockchain to support data storing and modifying. Smart contract related stuff can come later, but the foundation should be designed with contracts in mind. 

If you'd like to contribute please feel free, or send me a message! 

Progress:
Block mining working

To-do:
Incorporate transactions into Blocks, figure out the best way to use merkle tree with networking to share the chain to non-full nodes..

Design:

Every request is a Transaction, Blocks in the chain store hashes of each Transaction, and the Blockchain structure stores the list of blocks. Transactions are immutable, and peers can be used to validate/verify a request. This design is still very early, and will likely change as I learn more about the topic.

example: User A requests balance of Public Key B

-> User A node asks it's neighbors, and each neighbor asks it's next one. If one node along the way gives a different value than the rest of the nodes, we know this node is bad. In that case, it can be ignored, and the most prevalent answer combined with the age of the node will be selected.
