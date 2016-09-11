const fs = require('fs');
const path = require('path');

const browsersync = require('browser-sync');

const gulp = require('gulp');

const dom = require('gulp-dom');
const htmlmin = require('gulp-htmlmin');
const imagemin = require('gulp-imagemin');
const plumber = require('gulp-plumber');
const rename = require('gulp-rename');
const watch = require('gulp-watch');

gulp.task('default', ['serve', 'post']);

// -------------------------------------------------------------------
// browser-sync
// -------------------------------------------------------------------

gulp.task('serve', function() {
  browsersync({
    server: './build',
    port: 4000,
    files: [
      "./build/**/*.html",
      "./build/**/img/*"
    ]
  });
});

// -------------------------------------------------------------------
// post
// -------------------------------------------------------------------

gulp.task('post',
          ['optimize-html',
           'optimize-img']);

gulp.task('optimize-html', function() {
  var p = ['./**/*.html', '!./node_modules/**/*.html', '!./build/**/*.html'];
  return gulp.src(p)
    .pipe(watch(p, {verbose: true}))
    .pipe(dom(function() {
      var doc = this;
      var footnotes = doc.getElementById('footnotes');
      var content = doc.getElementById('content');
      var bibliography = doc.getElementById('bibliography');
      if (bibliography)
        content.insertBefore(bibliography, footnotes);
      return doc;
    }))
    .pipe(htmlmin({
      removeComments: true,
      collapseWhitespace: true,
      removeEmptyAttributes: true,
      minifyJS: true,
      minifyCSS: true
    }))
    .pipe(rename({basename: 'index'}))
    .pipe(gulp.dest('./build/'));
});

gulp.task('optimize-img', ['optimize-html'], function() {
  var p = ['./**/img/*', '!./node_modules/**/img/*', '!./build/**/img/*'];
  return gulp.src(p)
    .pipe(watch(p, {verbose: true}))
    .pipe(imagemin())
    .pipe(gulp.dest('./build'));
});

// -------------------------------------------------------------------
// deploy
// -------------------------------------------------------------------

gulp.task('deploy', function(){
  return gulp.src('./build/**/*')
    .pipe(gulp.dest('../gh-pages'));
});
