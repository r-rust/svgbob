#' SvgBob
#'
#' Converts ascii art into beautiful svg images.
#'
#' @export
#' @rdname svgbob
#' @useDynLib svgbob R_ascii2svg
#' @param text input ascii text
#' @param svgfile output file to write svg
#' @references Live demo: \url{http://ivanceras.github.io/svgbob-editor/}
#' @examples text <- readLines(system.file('examples/circuits.bob', package = 'svgbob'))
#' svgbob(text[1:41], 'circuits.svg')
#' utils::browseURL('circuits.svg')
#'
#' # Convert to png
#' rsvg::rsvg_png('circuits.svg', 'circuits.png', width = 2000)
#' utils::browseURL('circuits.png')
svgbob <- function(text, svgfile = tempfile()){
  ascii <- paste(enc2utf8(text), collapse = "\n")
  .Call(R_ascii2svg, ascii, svgfile)
  svgfile
}
