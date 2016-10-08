const F = require('fs');
const P = require('path');
const D = require('del');

const $ = require('gulp');
const $changed = require('gulp-changed');
const $dom = require('gulp-dom');
const $htmlmin = require('gulp-htmlmin');
const $plumber = require('gulp-plumber');
const $rename = require('gulp-rename');

const browsersync = require('browser-sync');
const reload = (done) => {browsersync.reload(); done();};

$.task('default', $.series(
  () => D(['./build']), $.parallel(serve, watch)));

// -------------------------------------------------------------------
// watch
// -------------------------------------------------------------------

function watch() {
  $.watch(['./**/*.html'],
          {ignoreInitial: false,
           ignored: ['node_modules/**/*.html', 'build/**/*.html']},
          $.series(post, reload));
}

// -------------------------------------------------------------------
// serve
// -------------------------------------------------------------------

function serve() {
  browsersync({
    server: './build',
    port: 4000
  });
}

// -------------------------------------------------------------------
// post
// -------------------------------------------------------------------

function post () {
  var p = ['./**/*.html',
           '!./node_modules/**/*', '!./build/**/*'];
  return $.src(p)
    .pipe($changed('./build'))
    .pipe($plumber())
    .pipe($dom(function() {
      var doc = this;
      var footnotes = doc.getElementById('footnotes');
      var content = doc.getElementById('content');
      var bibliography = doc.getElementById('bibliography');
      if (bibliography)
        content.insertBefore(bibliography, footnotes);
      return doc;
    }))
    .pipe($htmlmin({
      removeComments: true,
      collapseWhitespace: true,
      removeEmptyAttributes: true,
      minifyJS: true,
      minifyCSS: true
    }))
    .pipe($rename({basename: 'index'}))
    .pipe($.dest('./build/'));
}

// -------------------------------------------------------------------
// deploy
// -------------------------------------------------------------------

$.task('deploy', $.series(
  () => D(['../gh-pages/*'], {force: true}),
  () => $.src('./build/**/*').pipe($.dest('../gh-pages'))));
