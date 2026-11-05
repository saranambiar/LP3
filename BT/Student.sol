// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {

    struct Student {
        uint id;
        string name;
        uint marks;
    }

    Student[] public students;           // array of structs

    function addStudent(uint _id, string memory _name, uint _marks) public {
        students.push(Student(_id, _name, _marks));
    }

    function getStudent(uint index) public view returns (uint, string memory, uint) {
        Student memory s = students[index];
        return (s.id, s.name, s.marks);
    }

    function getCount() public view returns (uint) {
        return students.length;
    }

    // fallback: runs if someone sends ether/data with no matching function
    fallback() external payable {}
    receive() external payable {}
}