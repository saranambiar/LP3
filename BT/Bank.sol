// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {
    mapping(address => uint) balances;     // each account's balance (in wei)

    // payable = this function can receive ether
    function deposit() public payable {
        balances[msg.sender] = balances[msg.sender] + msg.value;
    }

    function withdraw(uint amount) public {
        require(balances[msg.sender] >= amount, "Not enough balance");
        balances[msg.sender] = balances[msg.sender] - amount;
        payable(msg.sender).transfer(amount);
    }

    function getBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}

// Simpler version with no real ether (just numbers), if your lab only asks for logic
contract SimpleBank {
    uint balance = 0;

    function deposit(uint amount) public {
        balance = balance + amount;
    }

    function withdraw(uint amount) public {
        require(balance >= amount, "Not enough balance");
        balance = balance - amount;
    }

    function getBalance() public view returns (uint) {
        return balance;
    }
}