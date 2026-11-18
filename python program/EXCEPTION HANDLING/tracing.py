# Configure logging format
logging.basicConfig(
    filename='detailed_errors.log',
    level=logging.ERROR,
    format='%(asctime)s - [%(levelname)s] - %(message)s'
)

class CustomValidationError(Exception):
    """Custom exception with additional contextual attributes."""
    def __init__(self, message, error_code, payload=None):
        super().__init__(message)
        self.error_code = error_code
        self.payload = payload

def log_detailed_exception(exc: Exception, user_context: dict = None):
    """
    Logs an exception along with its type, message, custom attributes,
    system traceback details, and custom execution context.
    """
    exc_type, exc_value, exc_tb = sys.exc_info()
    tb_info = traceback.extract_tb(exc_tb)[-1]  # Get the last stack frame where error occurred

    # Gather standard and traceback details
    details = {
        "exception_type": exc_type.__name__ if exc_type else type(exc).__name__,
        "message": str(exc),
        "file": tb_info.filename,
        "line_number": tb_info.lineno,
        "function": tb_info.name,
        "code_context": tb_info.line,
    }

    # Extract dynamic custom attributes attached to the exception instance
    custom_attrs = {
        attr: getattr(exc, attr)
        for attr in dir(exc)
        if not attr.startswith("_") and attr not in ("args", "with_traceback")
    }
    if custom_attrs:
        details["custom_attributes"] = custom_attrs

    # Attach runtime context if provided
    if user_context:
        details["runtime_context"] = user_context

    # Log structured exception output
    logging.error("Exception occurred with detailed context:\n%s", details, exc_info=True)


# --- Example Usage ---

def process_user_data(user_id, age):
    try:
        if age < 0:
            raise CustomValidationError(
                message="Age cannot be negative",
                error_code="INVALID_AGE_VALUE",
                payload={"provided_age": age, "min_allowed": 0}
            )
        result = 100 / age  # Could raise ZeroDivisionError
        return result

    except Exception as exc:
        log_detailed_exception(exc, user_context={"user_id": user_id, "action": "profile_update"})


# Trigger the custom exception with detailed attributes
process_user_data(user_id="USR-1042", age=-5)