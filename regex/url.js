/**
 * Author: matthew6868(mxu.public@outlook.com)
 * Date: 2016-11-23
 * 
 * Ref: http://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url
 */

function isUrl (url) {
  return /(https?:\/\/(?:www\.|(?!www))[^\s\.]+\.[^\s]{2,}|www\.[^\s]+\.[^\s]{2,})$/i.test(uri)
}