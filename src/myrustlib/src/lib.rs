// Import dependencies
extern crate svg;
extern crate svgbob;

// Modules are other .rs source files
mod ascii2svg;

// Export functions called by R
pub use ascii2svg::run_ascii2svg;
