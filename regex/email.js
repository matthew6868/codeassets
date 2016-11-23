/**
 * Author: matthew6868(mxu.public@outlook.com)
 * Date: 2016-11-23
 * 
 * Ref: http://stackoverflow.com/questions/46155/validate-email-address-in-javascript
 */

function isEmail (email) {
  return /^\s*[a-z0-9!#$%&'*+\/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+\/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+(?:[A-Z]{2}|com|org|net|gov|mil|biz|info|mobi|name|aero|jobs|museum)\b/i.test(email)
}