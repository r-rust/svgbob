use std::ffi::CStr;
use std::os::raw::c_char;
use svgbob::Grid;
use svgbob::Settings;
use svg;

#[no_mangle]
pub extern fn run_ascii2svg(ascii: *const c_char, svgfile: *const c_char){
    unsafe {
      let input = CStr::from_ptr(ascii);
      let output = CStr::from_ptr(svgfile);
      let g = Grid::from_str(input.to_str().unwrap(), &Settings::no_optimization());
      let svg = g.get_svg();
      svg::save(output.to_str().unwrap(), &svg).unwrap();
    }
}
