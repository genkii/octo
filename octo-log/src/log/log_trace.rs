use crate::{log::octo_log, log_level::LogLevel};
use std::ffi::c_char;

#[unsafe(no_mangle)]
pub extern "C" fn log_trace(context: *const c_char, message: *const c_char) {
    octo_log(context, message, LogLevel::Trace);
}
