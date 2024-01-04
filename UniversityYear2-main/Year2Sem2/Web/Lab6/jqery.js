/* When the user clicks on the button,
toggle between hiding and showing the dropdown content */
function myFunction(target) {
   $(target).next().toggleClass("show");
}

$(document).ready(() => {
    // Close the dropdown if the user clicks outside of it
    $(window).on("click", function(jEvent) {
        let e = jEvent.originalEvent;

        if (!$(e.target).hasClass("dropbtn")) {
            $(".dropdown-content").removeClass("show");
        }
    });

    $(".navbar").css({
        "overflow": "hidden",
        "background-color": "#333",
        "font-family": "Arial, Helvetica, sans-serif"
    });

    $(".navbar > a").css({
        "float": "left",
        "font-size": "16px",
        "color": "white",
        "text-align": "center",
        "padding": "14px 16px",
        "text-decoration": "none"
    });

    $(".dropdown").css({
        "float": "left",
        "overflow": "hidden"
    });

    $(".dropdown > .dropbtn").css({
        "cursor": "pointer",
        "font-size": "16px",
        "border": "none",
        "outline": "none",
        "color": "white",
        "padding": "14px 16px",
        "background-color": "inherit",
        "font-family": "inherit",
        "margin": "0"
    });


    $(".dropdown-content").css({
        "height": "0",
        "transition": "height 2s",
        "overflow": "hidden",
        "position": "absolute",
        "background-color": "#f9f9f9",
        "min-width": "160px",
        "box-shadow": "0px 8px 16px 0px rgba(0,0,0,0.2)",
        "z-index": "1"
    });

    $(".dropdown-content > a").css({
        "float": "none",
        "color": "black",
        "padding": "12px 16px",
        "text-decoration": "none",
        "display": "block",
        "text-align": "left"
    });
})

