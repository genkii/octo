use crate::{log::log, log_level::LogLevel};
use std::ffi::c_char;

#[unsafe(no_mangle)]
pub extern "C" fn log_error(context: *const c_char, message: *const c_char) {
    log(context, message, LogLevel::Error);
}
