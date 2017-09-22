var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: '尚名校' });
});

/*学生课程，学生端首页*/
router.get('/student', function(req, res, next) {
  res.render('student_course', { title: '尚名校学生端' });
});
/*学生推荐课程*/
router.get('/student_re', function(req, res, next) {
  res.render('student_re', { title: '尚名校学生端' });
});
/*学生个人详情*/
router.get('/student_detail', function(req, res, next) {
  res.render('student_detail', { title: '尚名校学生端' });
});
module.exports = router;
