/**
 * Author: matthew6868(mxu.public@outlook.com)
 * Date: 2016-11-23
 */

function isPhone (phone) {
  return /^(1(([35][0-9])|(47)|[8][01236789]))\d{8}$/.test(phone)
}