pub mod log_debug;
pub mod log_error;
pub mod log_info;
pub mod log_trace;
pub mod log_warn;

use crate::log_level::{LogLevel, MIN_LEVEL};
use owo_colors::OwoColorize;
use std::{
    ffi::{CStr, c_char},
    sync::atomic::Ordering,
};

#[unsafe(no_mangle)]
pub extern "C" fn octo_log(context: *const c_char, message: *const c_char, log_level: LogLevel) {
    if (log_level as u8) < MIN_LEVEL.load(Ordering::Relaxed) {
        return;
    }

    let log_flag = match log_level {
        LogLevel::Trace => "[TRACE]".purple().to_string(),
        LogLevel::Debug => "[DEBUG]".magenta().to_string(),
        LogLevel::Info => "[INFO]".blue().to_string(),
        LogLevel::Warn => "[WARN]".yellow().to_string(),
        LogLevel::Error => "[ERROR]".red().to_string(),
    };

    let context = unsafe { CStr::from_ptr(context) };
    let message = unsafe { CStr::from_ptr(message) };

    println!(
        "{}: [{}] {}",
        log_flag,
        context.to_string_lossy(),
        message.to_string_lossy()
    );
}
