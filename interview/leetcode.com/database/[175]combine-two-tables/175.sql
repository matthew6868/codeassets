/**
Source: https://leetcode.com/problems/combine-two-tables/
Author: matthew6868(mxu.public@outlook.com)
Date: 2016-11-02

175. Combine Two Tables
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId is the primary key column for this table.
Table: Address

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId is the primary key column for this table.

Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:

FirstName, LastName, City, State

*/
# Write your MySQL query statement below
select p.FirstName as FirstName, p.LastName as LastName, a.City as City, a.State as State from Person p LEFT JOIN Address a ON p.PersonId=a.PersonId